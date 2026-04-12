from sys import exit
N = int(input())
H = [int(n) for n in input().split()]
# a = [int(input()) for _ in range(N)]
# S = str(input())
# L = len(S)
# T = str(input())
# exit()
tmp = H[0]
ans = 1
for i in range(1,len(H)):
    if(tmp <= H[i]):
        ans+=1
        tmp = H[i]
print(ans)
