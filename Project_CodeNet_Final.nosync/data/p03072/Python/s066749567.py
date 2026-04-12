from sys import stdin

H = []
N = int(stdin.readline().rstrip())
H = [int(x) for x in stdin.readline().rstrip().split()]

count = 1
for i in range(1,N):
    flag = 0
    for j in range(0,i):
        if H[j] > H[i]:
            flag = 1
    if flag == 0:
        count +=1
    
print(count)