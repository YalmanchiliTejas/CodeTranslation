N = int(input())
Hlist = list(map(int, input().split()))

count = 1
for i in range(N-1):
    if max(Hlist[:i+1]) <= Hlist[i+1]:
        count += 1

print(count)