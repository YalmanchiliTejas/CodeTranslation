hand = "11111112222222221111211121"
#       abcdefghijklmnopqrstuvwxyz

while True:
    s = input()
    if s == "#":
        break

    num = [ord(c) - ord('a') for c in s]
    cnt = 0
    for i in range(len(num) - 1):
        if hand[num[i]] != hand[num[i + 1]]:
            cnt += 1
    print(cnt)
