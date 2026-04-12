import itertools

n, m = map(int, input().split())
a_list = []
b_list = []
for i in range(m):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

link_flag = 1
cnt = 0

for k in itertools.permutations(range(n)): #順列を生成して、それらに対して処理
    if k[0] != 0:
        break
    link_flag = 1
    for i in range(len(k)-1):
        if link_flag == 0:
            break
        link_flag = 0
        for j in range(m):
            if k[i]+1 == a_list[j]:
                if k[i+1]+1 == b_list[j]:
                    link_flag = 1
                    #print(k,a_list[j],b_list[j])
                    break
            if k[i]+1 == b_list[j]:
                if k[i+1]+1 == a_list[j]:
                    link_flag = 1
                    #print(k,a_list[j],b_list[j])
                    break
        if i == len(k)-2 and link_flag ==1:
            cnt += 1
print(cnt)
