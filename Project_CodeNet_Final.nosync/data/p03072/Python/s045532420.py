N = int(input())
H = [int(i) for i in input().split()]
count = 1
for i in range(1,len(H)):
    if H[i] >= max(H[:i]):
        count += 1

print(count)
