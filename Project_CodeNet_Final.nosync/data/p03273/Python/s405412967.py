#他の方のきれいなACのから勉強させてもらいました

h,w=map(int, input().split())
a1=[list(input()) for _ in range(h)]
# print(a1)
a2=[b for b in a1 if b.count('#')]
# print(a2)
a3=[b for b in list(zip(*a2)) if b.count('#')]
# print(a3)
ans=list(zip(*a3))
# print(ans)
for i in ans:
    print(''.join(i))