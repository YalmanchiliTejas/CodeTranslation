N = input()
Hi = input().split()
count = 0
mV = 0
for i in range(int(N)):
       if int(Hi[i]) >= int(mV):
           count += 1
           mV = Hi[i]
print(count)