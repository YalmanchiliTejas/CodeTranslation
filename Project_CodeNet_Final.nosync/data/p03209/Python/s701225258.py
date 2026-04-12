import sys
import string
n = raw_input()
n,k = n.split(' ') 

l=[1]
f=[1]
for i in range(55):
    l.append(l[len(l)-1]*2+3)
    f.append(f[len(f)-1]*2+1)

def s(k,level):
    if (level==0):
        if (k>0): return 1
        return 0
    if (k==1): return 0
    if (k>=l[level]): return f[level]
    if (k<l[level]):
        if (k<=l[level-1]+1):
            return s(k-1,level-1)
        if (k==l[level-1]+2):
            return 1+s(k-1,level-1)
        return 1+f[level-1]+s(k-1-1-l[level-1],level-1)

n = string.atoi(n)
k = string.atoi(k)
print (s(k,n))


