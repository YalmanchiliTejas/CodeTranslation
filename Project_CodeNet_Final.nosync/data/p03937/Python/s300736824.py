import collections
h,w = map(int,input().split())
a = []
cnt = 0
for i in range(h):
    aa = list(input())
    c = collections.Counter(aa)
    cnt += c['#']
    a.append(aa)
cnt -= 1
if cnt == h+w-2:
    print('Possible')
else:
    print('Impossible')
