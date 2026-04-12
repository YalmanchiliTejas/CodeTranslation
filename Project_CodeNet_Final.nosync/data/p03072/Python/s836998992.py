n = int(input())
hs = [int(i) for i in input().split()]
flag = 1
for i in range(1,n):
    if all(hs[j] <= hs[i] for j in range(i)):
        flag = flag + 1
print(flag)
