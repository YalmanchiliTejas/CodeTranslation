a = input().split()
N = list(map(int,input().split()))
A = int(a[0])

counter = 1

for i in range(2,A+1):
  N_new = N[0:i]
  N_new_len = len(N_new)
  if max(N_new) == N_new[int(N_new_len)-1]:
    counter += 1
print(counter)