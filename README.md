Parabyte String (pstring.h)
===
A library for the C language, for working with strings, Some features of high-level languages ​​such as searching in a string or cutting it

## Papar Information
- Title:  `Parabyte String`
- Authors:  `Mahdi Hosseini Asaad`


## Install
- For public installation
``` bash
make install
```
- You can use it directly in your project without installing it :
```c
#include "pstring.h"
```

## Example
  ```c
  #include  <stdio.h>
  #include "pstring.h"

  int main ( )
  {
    char *str = "Hallo ich bin Mahdi";
    printf ("%s\n", separate (str, 0, 5) );
  }
  ```

## Directory Hierarchy
```
|—— LICENSE
|—— README.md
|—— make
|—— pstring.h
```
  
## License
GNU GENERAL PUBLIC LICENSE Version 3 

## Contact us
- Email : Libre.hosseini@Gmail.com
- Matrix : @librehosseini:matrix.org
