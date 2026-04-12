N = int(input())
L = [i for i in map(int,input().split())]
t = 0
res = 0
for i in range(len(L)):
    for j in range(i):
        if L[j] > L[i]:
            t = 1
            break
    if t==0:
        res += 1
    t = 0
print(res)