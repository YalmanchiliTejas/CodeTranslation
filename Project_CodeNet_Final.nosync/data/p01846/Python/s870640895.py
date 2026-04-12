def parse_line(line):
  ret = []
  for c in line:
    if c == "b":
      ret.append("b")
    else:
      for _ in range(int(c)):
        ret.append(".")
  return ret

def parse_jfen(s):
  return list(map(parse_line, s.split("/")))

def to_jfen(mp):
  ret = ""
  cnt = 0
  for line in mp:
    cnt = 0
    for c in line:
      if c == "b":
        if cnt != 0:
          ret += str(cnt)
          cnt = 0
        ret += "b"
      else:
        cnt += 1
    if cnt != 0:
      ret += str(cnt)
    ret += "/"
  return ret[:-1] 

while True:
  s = input()
  if s == "#":break
  mp = parse_jfen(s)
  a, b, c, d = map(int, input().split())
  mp[a - 1][b - 1] = "."
  mp[c - 1][d - 1] = "b"
  print(to_jfen(mp))
