N = int(input())
H = list(map(int, input().split()))  # 入力のときに N を使う必要はありません

highest = 0
cnt = 0
for h in H:
    if h >= highest:
        highest = h
        cnt += 1

print(cnt)
    
    