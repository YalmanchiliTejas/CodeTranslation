n = int(input())
h = [int(i) for i in input().split()]
m_h = 0
cnt = 0

for i in h:
  if i >= m_h:
    cnt += 1
  m_h = max(m_h,i)

print(cnt)