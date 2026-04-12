N = int(input())
H = list(map(int, input().split(' ')))

highest = 0
count= 0

for top_i in H:
    if(top_i >= highest):
        count += 1
        highest = top_i

print(count)