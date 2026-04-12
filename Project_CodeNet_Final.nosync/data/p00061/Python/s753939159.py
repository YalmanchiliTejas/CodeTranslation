p = []
q = []
while(1):
    a,b = [int(i) for i in input().split(",")]
    if a == 0 and b == 0:
        break
    p.append(a)
    q.append(b)
q_ = sorted(list(set(q)))
q_rank = [i+1 for i in range(len(q_))[::-1]]
q_dic = dict(zip(q_,q_rank))
rank = dict(zip(p,[q_dic[i] for i in q]))

while(1):
    try:
        a = int(input())
        print(rank[a])
    except EOFError:
        break
