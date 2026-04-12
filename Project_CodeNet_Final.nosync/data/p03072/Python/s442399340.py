import sys
N = sys.stdin.readline()
N = int(N)

#print(N)
#for i in range(N):
H = sys.stdin.readline().split()
#print(H)

max_H = 0
cnt = 0
for i in range(len(H)):
    if(max_H<=int(H[i])):
#        print(H[i])
        max_H = int(H[i])
        cnt += 1
#    else:
#        print("m",max_H)
    
print(cnt)