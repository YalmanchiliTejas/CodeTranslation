N = int(input())
h_list = map(int,input().split())
cnt = 0
max_h = 0

for h in h_list:
    max_h = max(max_h, h)
    if max_h == h:
        cnt += 1
  
print(cnt)