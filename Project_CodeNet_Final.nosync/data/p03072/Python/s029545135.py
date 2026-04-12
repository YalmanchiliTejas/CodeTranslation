N = int(input())

H_i = input().split()
H_i = [float(n) for n in H_i]

ocean_view_count = 0

for i in range(N):
   if max(H_i[:i+1]) == H_i[i]:
       ocean_view_count += 1
     
print(ocean_view_count)