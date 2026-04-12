N = int(input())
mountains = list(map(int, input().split()))

highest = mountains[0]

cnt = 0

for mt in mountains:
    if mt >= highest:
        cnt += 1
        highest = mt
        
print(cnt)