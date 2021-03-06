#ifndef __NrrdConfigure_h
#define __NrrdConfigure_h
// Configure compile time dependent code
// BUG: 0005904 shows that special action must be taken for Mac 64 bit systems.
// See: http://public.kitware.com/Bug/view.php?id=5904
/* 32 or 64 bits.  */
/* All compilers that support Mac OS X define __LP64__ if the architecture is
  64 bits. */
#define CMAKE_SIZEOF_VOID_P 8
#if !defined(__APPLE__)
 #if CMAKE_SIZEOF_VOID_P == 8
   #define TEEM_32BIT 0
 #else
   #define TEEM_32BIT 1
 #endif
#elif defined(__LP64__) && __LP64__
 #define TEEM_32BIT 0
#else
 #define TEEM_32BIT 1
#endif


/* what byte order */
/* All compilers that support Mac OS X define either __BIG_ENDIAN__ or
   __LITTLE_ENDIAN__ to match the endianness of the architecture being
   compiled for. This is not necessarily the same as the architecture of
   the machine doing the building. In order to support Universal Binaries on
   Mac OS X, we prefer those defines to decide the endianness.
   Elsewhere use the platform check result.  */
#if !defined(__APPLE__)
  #if 0
    #define TEEM_ENDIAN 4321
  #else
    #define TEEM_ENDIAN 1234
  #endif
#else
  #if defined(__BIG_ENDIAN__)
    #define TEEM_ENDIAN 4321
  #else
    #define TEEM_ENDIAN 1234
  #endif
#endif

#endif // __NrrdConfigure_h
