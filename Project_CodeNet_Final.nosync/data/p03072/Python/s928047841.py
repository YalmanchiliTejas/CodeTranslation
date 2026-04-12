N = int(input())
H=map(int, input().split())
_max = 0
ans = 0
for h in H:
    if h >= _max:
        ans += 1
        _max = h
print(ans)