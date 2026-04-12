n = int(input())
h_para = [int(i) for i in input().split()]

able_h = []
for i in range(n):
    count = 0
   

    

    for j in range(i):
        if h_para[i] >= h_para[j] :
            count = count
        else :
            count += 1
    if count == 0 : able_h.append(i)

print(len(able_h))