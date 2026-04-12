to_bin = dict(zip([chr(i) for i in range(ord("A"), ord("Z") + 1)] + [" ", ".", ",", "-", "'", "?"],
                  [bin(i)[2:7].zfill(5) for i in range(2 ** 5)]))
to_chr = {"101":" ", "000000":"'", "000011":",", "10010001":"-", "010001":".", "000001":"?", "100101":"A", "10011010":"B",
          "0101":"C", "0001":"D", "110":"E", "01001":"F", "10011011":"G", "010000":"H", "0111":"I", "10011000":"J",
          "0110":"K", "00100":"L", "10011001":"M", "10011110":"N", "00101":"O", "111":"P", "10011111":"Q", "1000":"R",
          "00110":"S", "00111":"T", "10011100":"U", "10011101":"V", "000010":"W", "10010010":"X", "10010011":"Y", "10010000":"Z"}

while True:
  try:
    s = input()
  except EOFError:
    break
  bs = "".join([to_bin[c] for c in s])
  ans = ""
  while True:
    length = 9
    for i in range(length):
      if bs[:i] in to_chr:
        ans = ans + to_chr[bs[:i]]
        bs = bs[i:]
        break
    else:
      break
  print(ans)
