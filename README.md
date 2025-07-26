AMIGA SPRITE CREATION UTILITY
code by Jake Aigner July, 2025

    List of Commands:
            endshell :    quit.
            reset    :    reset sprite
            gen      :    generate sprite hex data from entered values
    color data can be entered in one line at a time (width of 16)
    0 = transparent 
    1-3 = sprite colors (check hardware manual for more info)
     example:
        > reset
        > 0000012233221000
        > 0001223333332210
        > 0000012233221000
        > gen

	sprite:
    	    DC.W $XXYY,$ZZ00    ;VSTART (XX),HSTART (YY),VSTOP (ZZ) (VSTOP = VSTART + 3)
    	    DC.W $04C8,$03F0
    	    DC.W $13F2,$0FFC
   	    DC.W $04C8,$03F0
    	    DC.W $0000,$0000    ;end of sprite data

