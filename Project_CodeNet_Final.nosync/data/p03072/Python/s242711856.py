n = int(input())
m_list = list(map(int, input().split()))
max_num = 0
c = 0
for i in range(n):
  if m_list[i] - max_num >= 0:
    c += 1
    max_num = m_list[i]

print(c)