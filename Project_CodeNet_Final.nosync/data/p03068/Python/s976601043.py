def main(word, num):
    strs = list(word)
    target = strs[num-1]

    new_strs = []
    for s in strs:
        if s != target:
            s = "*"
        new_strs.append(s)

    return ''.join(new_strs)


if __name__ == "__main__":
    input()
    word = input()
    num = int(input())
    print(main(word, num))
