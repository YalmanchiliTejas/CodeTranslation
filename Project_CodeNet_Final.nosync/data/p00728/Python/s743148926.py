list1=[]
while True: 
    n = int(input())
    if n == 0:
        break #n が 0 のときにループから抜ける
    else:
        for i in range(n):
            j=int(input())
            list1.append(j)
        list1.remove(max(list1))
        list1.remove(min(list1))
        print(sum(list1)//len(list1))
        list1=[]
