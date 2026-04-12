n = int(input())
h = [int(i) for i in input().split()]

num = 1
for i in range(1,len(h)):
    if h[i] >= max(h[:i]):
        num += 1

print(num)