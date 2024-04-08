# Archivo: suma_asm.S

.text
.align 2
.globl suma_asm

suma_asm:
    add a0, a0, a1   # Sumar los argumentos
    ret              # Devolver el resultado
