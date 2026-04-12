N = int(input())
H = list(map(int, input().split()))

maximum = 0
counter = 0

for h in H:
  # それまでの最大値であれば見られる
  if maximum <= h:
    maximum = h
    counter += 1
print(counter)