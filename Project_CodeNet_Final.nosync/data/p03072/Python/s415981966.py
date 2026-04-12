n = int(input())
list1 = list(map(int,input().split()))
count = 1
the_lowrst = list1[0]
if n == 1:
    print(1)
    exit()
for i in range(1,n):
    if the_lowrst <= list1[i]:
        the_lowrst = list1[i]
        count += 1
print(count)