n = int(input())
h = list(map(int, input().split(" ")))

ans = 0

h_max = h[0]

for i in h:
    if(h_max <= i):
        ans += 1
        h_max = i

print(ans)