n = int(input())
h = list(map(int,input().split(" ")))

result = 0
now_max = 0

for i in range(n):
    if h[i] >= now_max:
        result = result + 1
        now_max = h[i]

print(result)
