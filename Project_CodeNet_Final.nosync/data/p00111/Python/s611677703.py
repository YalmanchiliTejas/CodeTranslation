#!/usr/bin/env python
from __future__ import division, print_function
from sys import stdin, exit


code_table = {chr(65+i): '{:05b}'.format(i) for i in range(26)}
code_table.update({' ': '11010', '.': '11011', ',': '11100', '-': '11101',
                   "'": '11110', '?': '11111'})

decrypt = {
    '101': ' ', '000000': "'", '000011': ',', '10010001': '-',
    '010001': '.', '000001': '?', '100101': 'A', '10011010': 'B',
    '0101': 'C', '0001': 'D', '110': 'E', '01001': 'F',
    '10011011': 'G', '010000': 'H', '0111': 'I', '10011000': 'J',
    '0110': 'K', '00100': 'L', '10011001': 'M', '10011110': 'N',
    '00101': 'O', '111': 'P', '10011111': 'Q', '1000': 'R',
    '00110': 'S', '00111': 'T', '10011100': 'U', '10011101': 'V',
    '000010': 'W', '10010010': 'X', '10010011': 'Y', '10010000': 'Z'}


def main():
    for line in stdin:
        buf = ''
        for c in ''.join(code_table[c] for c in line.rstrip('\r\n')):
            buf += c
            plain = decrypt.get(buf)
            if plain:
                print(plain, end='')
                buf = ''
        print()
    exit()


if __name__ == '__main__':
    main()