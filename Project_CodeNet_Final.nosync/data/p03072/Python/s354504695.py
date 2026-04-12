N = int(input())
h_vals = input().split(' ')
h_vals = [int(h) for h in h_vals]
hmax = -1
count = 0
for h in h_vals:
  if hmax <= h:
  	hmax = h
  	count+=1
print(count)
