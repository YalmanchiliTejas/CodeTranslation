# coding: utf-8
import functools

def M(s):
    s=s.split('+')
    for i in range(len(s)):
        if '*' in s[i]:
            s[i]=functools.reduce(lambda x,y:str(int(x)*int(y)),s[i].split('*'))
    return int(functools.reduce(lambda x,y:str(int(x)+int(y)),s))

def L(s):
    ret=0
    i=0
    ope=1
    while i<len(s):
        if i%2==0:
            if ope==1:
                ret+=int(s[i])
            else:
                ret*=int(s[i])
        else:
            if s[i]=='+':
                ope=1
            else:
                ope=2
        i+=1
    return ret

original=input()
ans=int(input())
f=0
if ans==M(original):
    f+=1
if ans==L(original):
    f+=2

if f==0:
    print('I')
elif f==1:
    print('M')
elif f==2:
    print('L')
else:
    print('U')


