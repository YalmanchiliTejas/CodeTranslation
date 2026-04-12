def main():
  h,w = map(int, input().split())
  ans = []
  p = []
  for _ in range(h):
    s = input()
    if '#' in s:
      ans.append(list(s))
  for i in range(len(ans[0])):
    for j in range(len(ans)):
      if ans[j][i] == '#':
        break
      if j == len(ans)-1:
        p.append(i)
  p.sort(reverse=True)
  for i in p:
    for j in range(len(ans)):
      ans[j].pop(i)
  for i in range(len(ans)):
    s = ''.join(ans[i])
    print(s)

if __name__ == '__main__':
  main()