<?php
	class VariablesConstantVars{				
		private static $_admin_link;
		private static $_links;		
		
		public static function init($admin_link){
			self::$_admin_link = $admin_link;
			self::$_links = array("view" => self::$_admin_link . "/view",
  				 				 "add" => self::$_admin_link . "/add",
  				 				 "edit" => self::$_admin_link . "/edit/%",
  				 				 "delete" => self::$_admin_link . "/delete/%",);
		}
		
		public static function getAdminVariableLink(){
			return self::$_admin_link;
		}
		
		public static function getLinks(){
			return self::$_links;	
		}		
	}
?>