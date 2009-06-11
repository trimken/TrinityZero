-- ALTER TABLE db_version CHANGE COLUMN required_7908_02_mangos_creature_addon 
-- required_7908_03_mangos_creature_template_addon bit;


-- deleting unused datas

delete from `player_classlevelstats` where `level`>60;
delete from `player_levelstats` where `level`>60 or `race`>9;
delete from `playercreateinfo` where `race`>9;
delete from `playercreateinfo_action` where `race`>9;
delete from `playercreateinfo_item` where `race`>9;
delete from `playercreateinfo_spell` where `race`>9;
delete from `playercreateinfo_spell_custom` where `race`>9;