MOD = 1000000007

N=int(input())
A = list(map(int, input().split())) 

answer = 0
s = sum(A)

for a in A:
    s -=a
    answer += (a * s)
print(answer%MOD)