l = int(input())
c = 1
b4most = 0
answer = 0
ryokan = list(map(int, input().split()))
for data in ryokan:
    if b4most <= data:
        answer += 1
        b4most = data
print(answer)
