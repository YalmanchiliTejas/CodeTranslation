
def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

n = ii()
s = list(input())
k = ii()
for i in range(len(s)):
    if s[i] != s[k-1]:
        s[i] = '*'
print(''.join(s))