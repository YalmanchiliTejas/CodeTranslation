#! python.exe
dic = {}
for idx, c in enumerate("ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?"):
    dic[c] = str(format(idx,'b').zfill(5))

decode = {"101"      : " ", "0101"     : "C", "0110"     : "K", "00110"    : "S",
          "000000"   : "'", "0001"     : "D", "00100"    : "L", "00111"    : "T",
          "000011"   : ",", "110"      : "E", "10011001" : "M", "10011100" : "U",
          "10010001" : "-", "01001"    : "F", "10011110" : "N", "10011101" : "V",
          "010001"   : ".", "10011011" : "G", "00101"    : "O", "000010"   : "W",
          "000001"   : "?", "010000"   : "H", "111"      : "P", "10010010" : "X",
          "100101"   : "A", "0111"     : "I", "10011111" : "Q", "10010011" : "Y",
          "10011010" : "B", "10011000" : "J", "1000"     : "R", "10010000" : "Z"}
#print(dic)
while True:
    try:
        line = input()
    except:
        break
    s = ""
    for c in line:
        s += dic[c]
    ans = ""
    while len(s) > 5 or s.count("1") :
        for key in decode:
            n = len(key)
            if s[0:n] == key:
                ans += decode[key]
                s = s[n:]
                break
#        print(ans, s)
    print(ans)