# -*- coding: utf-8 -*-

import sys
import os
import math
import re
import random

# copy of cima code
# to confirm system is working correctly

en='ABCDEFGHIJKLMNOPQRSTUVWXYZ'+' .,-\'?'
de={
'101':' ','000000':'\'','000011':',','10010001':'-','010001':'.','000001':'?',
'100101':'A','10011010':'B','0101':'C','0001':'D','110':'E','01001':'F',
'10011011':'G','010000':'H','0111':'I','10011000':'J','0110':'K','00100':'L',
'10011001':'M','10011110':'N','00101':'O','111':'P','10011111':'Q','1000':'R',
'00110':'S','00111':'T','10011100':'U','10011101':'V','000010':'W','10010010':'X',
'10010011':'Y','10010000':'Z'
}
while 1:
    try:s=input()
    except:break
    a=b=c=''
    for x in s:a+=str(bin(en.index(x)))[2:].zfill(5)
    for x in a:
        b+=x
        if b in de:c+=de[b];b=''
    print(c)