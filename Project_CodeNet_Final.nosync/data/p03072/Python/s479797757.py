N = int(input())
H = list(map(int, input().split()))

maximum = 0
answer = 0
for Hi in H:
    if maximum <= Hi:
        answer += 1
    maximum = max(Hi, maximum)

print(answer)