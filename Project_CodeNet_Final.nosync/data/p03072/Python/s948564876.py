N = int(input())
H = list(map(int , input().split()))

highest_mountain = -1
count =0
for i in range(N):
    if (H[i] >= highest_mountain):
        count +=1
        highest_mountain = H[i]
print(count)
