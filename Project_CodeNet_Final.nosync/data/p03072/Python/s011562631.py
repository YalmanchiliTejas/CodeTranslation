N = int(input())
H = list(map(int,input().split()))

high = 0
cnt = 0
for mountain in H:
    if high <= mountain:
        high = mountain
        cnt += 1
print(cnt)