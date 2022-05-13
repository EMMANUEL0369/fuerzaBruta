#!/usr/bin/bash
gcc descifrado.c  -o descifrado
key=$(./descifrado 0 $(hexdump -C $1 | head -197 | tail -1 | tr -s '  ' ' '  | cut -d' ' -f2-17))
echo $key
cantidad=$(hexdump -C $1 | wc -l)
for (( c=1; c<=($cantidad); c++ ))
do  
  $(./descifrado $key $(hexdump -C $1 | head -$c | tail -1 | tr -s '  ' ' '  | cut -d' ' -f2-17)>>$2)
done
echo ""
