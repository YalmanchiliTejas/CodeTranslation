"""
map(int,input().split())

"""
N = int(input())
h = map(int,input().split())

hls =  []

for i in h:
    hls.append(i)

mx = hls[0]
cnt = 1
for i in range(1,N):
    if mx <= hls[i]:
        cnt += 1
        mx = hls[i]

print(cnt)
