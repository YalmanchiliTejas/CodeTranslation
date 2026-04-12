N = int(input())
H = map(int, input().split())
result = 0
H_MAX = 0
for h in H:
    if H_MAX <= h:
        H_MAX = h
        result += 1
print(result)