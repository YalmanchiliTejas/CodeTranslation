# coding: utf-8
x,y,z=map(int,input().split())
cnt=z
hum=0
while 1:
    cnt+=y+z#isu to haba tasu
    if cnt>x:#koeruka handan
        break
    hum+=1#koetenakya hairu
print(hum)