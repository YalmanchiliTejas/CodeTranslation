#! env/bin/local python3
# -*- coding: utf-8 -*-


def seki(array1: list, array2: list):
    results = []
    for a in array1:
        if a in array2:
            results.append(a)
            array2.remove(a)
    return results


def main():
    n = int(input())
    sentences = []
    while True:
        try:
            sentences.append(sorted(input(), reverse=True))
        except EOFError:
            break

    pocket = sentences[0].copy()

    for n, sentence in enumerate(sentences):
        pocket = seki(pocket, sentence)

    print(''.join(sorted(pocket)))


if __name__ == '__main__':
    main()
