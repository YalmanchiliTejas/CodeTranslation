N = int(input())
mx = 0
count = 0
st = input()
for i in range(N):
  if mx <= int(st.split()[i]):
    count += 1
    mx = int(st.split()[i])
print(count)