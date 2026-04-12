from sys import stdin
##  input functions for me
def ria(sep = ''):
    if sep == '' :
        return list(map(int, input().split())) 
    else: return list(map(int, input().split(sep)))
def rsa(sep = ''):
    if sep == '' :
        return input().split() 
    else: return input().split(sep)
def ri(): return int(input())
def rd(): return float(input())
def rs(): return input()
##

## main ##
N = ri()
H = ria()

cnt = 0
ma = 0
for i in range(N):
    if (H[i] >= ma ): cnt += 1
    ma = max(ma, H[i])

print(cnt)

    



