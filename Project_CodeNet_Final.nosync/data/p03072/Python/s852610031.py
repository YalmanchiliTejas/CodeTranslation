N = int(input())
list_ = input().split()
K = 1
H = int(list_[0])
for i in range(1,N):
 if int(list_[i]) >= H:
  K += 1
  H = int(list_[i])
print(K)