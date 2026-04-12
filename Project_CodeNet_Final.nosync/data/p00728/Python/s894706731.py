list2=[]
while True:
    try:
        N=int(input())
        list1=[int(input()) for _ in range(N)]
        list2.append(int((sum(list1)-max(list1)-min(list1))/(N-2)))
    except:
        break
for tmp in list2:
    print(tmp)
