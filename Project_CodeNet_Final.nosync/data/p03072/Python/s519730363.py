n = int(input())
mountains = list(input().split())
mountains = [int(i) for i in mountains]
ans = 0
idx = 0
for i in mountains:
    if i == max(mountains[:idx+1]):
        ans += 1
    idx += 1

print(ans)